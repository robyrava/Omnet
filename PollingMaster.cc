#include "PollingMaster.h"

Define_Module(PollingMaster);

void PollingMaster::initialize() {
    pollQueue = cPacketQueue(0, poll_queue_comp);
    flowTable = check_and_cast<FlowTableParameters *>(par("flowTable").objectValue());

    for(int i=0; i < flowTable->getFlowsArraySize(); i++) {
        cMessage *tmr = new cMessage("PollTimer");
        tmr->setKind(i);
        scheduleAt(flowTable->getFlows(i).period, tmr);
    }
}

void PollingMaster::handleMessage(cMessage *msg) {
    if(msg->isSelfMessage()) {

    }
}

static int PollingMaster::poll_queue_comp(cObject *a, cObject *b) {
    PollingRequest *ta = check_and_cast<PollingRequest *>(a);
    PollingRequest *tb = check_and_cast<PollingRequest *>(b);

    return (tb->getPriority()-ta->getPriority());
}
