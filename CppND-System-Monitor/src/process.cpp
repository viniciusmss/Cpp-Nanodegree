#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// Define custom constructor
Process::Process(int pid)
    : pid_(pid),
      command_(LinuxParser::Command(pid)),
      user_(LinuxParser::User(pid)){};

// DONE: Return this process's ID
int Process::Pid() const { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() const {
  // From https://stackoverflow.com/a/16736599
  float totaltime = LinuxParser::ActiveJiffies(Pid());  // In jiffies
  float uptime = LinuxParser::UpTime();                 // In seconds
  float secondsactive =
      uptime - (Process::UpTime() / sysconf(_SC_CLK_TCK));  // In seconds
  float cpu_usage =
      (totaltime / sysconf(_SC_CLK_TCK)) / secondsactive;  // In seconds
  return cpu_usage;
}

// DONE: Return the command that generated this process
string Process::Command() { return command_; }

// DONE: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Pid()); }

// DONE: Return the user (name) that generated this process
string Process::User() { return user_; }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() const { return LinuxParser::UpTime(Pid()); }

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const {
  return CpuUtilization() < a.CpuUtilization();
}