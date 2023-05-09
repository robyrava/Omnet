packet DataPacket {
    simtime_t genTime;
    bool lastBurstPacket = false;
};

message DataControlInfo {
    string destination;
};
