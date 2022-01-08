#include "processor.h"
#include "linux_parser.h"

using std::vector;
using std::string;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    vector<string> cpuUtil = LinuxParser::CpuUtilization();
    vector<int> infoStream;
    for (string s : cpuUtil) {
        int element = stoi(s);
        infoStream.emplace_back(element);
    }

    int user = infoStream[0];
    int nice = infoStream[1];
    int system = infoStream[2];
    int idle = infoStream[3];
    int iowait = infoStream[4];
    int irq = infoStream[5];
    int softirq = infoStream[6];
    int steal = infoStream[7];

    int PrevIdle_ = previdle + previowait;
    int Idle_ = idle + iowait;

    int PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal;
    int NonIdle = user + nice + system + irq + softirq + steal;

    int PrevTotal = PrevIdle_ + PrevNonIdle;
    int Total = Idle_ + NonIdle;

    int totald = Total - PrevTotal;
    int idled = Idle_ - PrevIdle_;

    float cpu_percentage = ((float) (totald - idled)) / totald;

    previdle = idle;
    previowait = iowait;
    prevuser = user;
    prevnice = nice;
    prevsystem = system;
    previrq = irq;
    prevsoftirq = softirq;
    prevsteal = steal;

    return cpu_percentage;
 }