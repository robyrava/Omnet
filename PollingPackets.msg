packet PollingRequest {
    string flow;
    int requestedFrames;
    long priority;
};

packet PollingData {
    string destination;
};

struct FlowTableEntry {
    string flow;
    string addr;
    simtime_t period;
    simtime_t deadline;
};

class FlowTableParameters extends cOwnedObject {
    FlowTableEntry flows[];
};