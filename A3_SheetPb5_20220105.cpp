//File name:A3_SheetPb5_20220105.cpp
//Purpose: Solving problem 5 (Task Manager)
//Author: Habiba Amr Abdelfattah
//ID: 20220105
//Section: S21
//Date: 4 - 12 -2023


#include <iostream>
#include <vector>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#else
#endif

using namespace std;
class Process {
public:
    string name; //of process
    int pid;     //of process
    size_t memoryUsage;  //of process

    Process(const string& n, int p, size_t m) : name(n), pid(p), memoryUsage(m) {} //default constructor
};

class ProcessManager {
private:
    vector<Process> processes;

#ifdef _WIN32

    void getWindowsProcesses() {
        //Windows-specific code from 27--->55
        DWORD  processes1[1024], cbNeeded, cProcesses; //number of process
        //datatype            //size needed for array
        if (EnumProcesses(processes1, sizeof(processes1), &cbNeeded)) {
            //Calculates the number of processes based on the size needed for the array.
            cProcesses = cbNeeded / sizeof(DWORD);
            for (size_t i = 0; i < cProcesses; i++) {
                //Opens a handle to the process with the specified process ID. It requests permission to query information about the process and read its memory.
                HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processes1[i]);
                if (hProcess != NULL) {
                    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
                    //szProcessName is an array of TCHAR characters.
                    //Tchar-->to write code that can be easily adapted to different character encodings
                    //szProcessName-->array of chars
                    //MAX_PATH---> is a constant that represents the maximum length of a file or directory path in the Windows API. It is typically defined as 260 characters.
                    //TEXT
                    //<unknown>---> initial value assigned to array
                    HMODULE hMod;
                    DWORD cbNeeded; //the size needed for the module array
                    if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) { //check if it is true?
                        GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
                        //returns the total size
                        //returns the size of a single element in the array.
                        //size_t numberOfElements in array = sizeof(szProcessName) / sizeof(TCHAR);
                        //Retrieves the base name of the executable file for the process and stores it in szProcessName
                        processes.emplace_back(szProcessName, static_cast<int>(processes1[i]), getProcessMemoryUsage(hProcess));
                    }
                    CloseHandle(hProcess);
                }
            }
        }
    }
    size_t getProcessMemoryUsage(HANDLE processHandle) {
        PROCESS_MEMORY_COUNTERS_EX pmc;
        if (GetProcessMemoryInfo(processHandle, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
            return pmc.PrivateUsage / 1024;  // Convert to KB
        }
        return 0;
    }


#endif

public:
    void getRunningProcesses() {
#ifdef _WIN32
        getWindowsProcesses();
#endif
    }

    void displayProcesses(const std::string& sortBy = "name") {
        if (sortBy == "name") {
            std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                return a.name < b.name;
            });
        } else if (sortBy == "pid") {
            std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                return a.pid < b.pid;
            });
        } else if (sortBy == "memory") {
            std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                return a.memoryUsage < b.memoryUsage;
            });
        } else {
            std::cout << "Invalid sorting key. Displaying processes sorted by name." << std::endl;
            std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                return a.name < b.name;
            });
        }

        for (const auto& process : processes) {
            std::cout << "Name: " << process.name << ", PID: " << process.pid << ", Memory Usage: " << process.memoryUsage << " KB\n";
        }
    }
};

int main() {
    ProcessManager processManager;
    processManager.getRunningProcesses();

    cout << "Processes sorted by name:\n";
    processManager.displayProcesses("name");

    cout << "\nProcesses sorted by PID:\n";
    processManager.displayProcesses("pid");

    cout << "\nProcesses sorted by memory usage:\n";
    processManager.displayProcesses("memory");

    return 0;
}