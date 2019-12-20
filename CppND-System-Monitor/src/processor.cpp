#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::stoi;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  string cpu, user, nice, system, idle, iowait, irq, softirq, steal, guest,
      guest_nice;
  string line;
  std::ifstream stream(LinuxParser::kProcDirectory +
                       LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal >> guest >> guest_nice;
  }

  // Method from https://stackoverflow.com/a/23376195
  int idletime = stoi(idle) + stoi(iowait);
  int nonidletime = stoi(user) + stoi(nice) + stoi(system) + stoi(irq) + stoi(softirq) + stoi(steal);
  float totaltime = idletime + nonidletime;
  
  return (totaltime - idletime)/totaltime;
}