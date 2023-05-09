#ifndef __SIMPLEETHERNET_POLLINGMASTER_H_
#define __SIMPLEETHERNET_POLLINGMASTER_H_

#include <omnetpp.h>
#include "PollingPackets_m.h"

using namespace omnetpp;

class PollingMaster : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    static int poll_queue_comp(cObject *a, cObject *b);

  protected:
    cPacketQueue pollQueue;
    FlowTableParameters *flowTable;
};

#endif
