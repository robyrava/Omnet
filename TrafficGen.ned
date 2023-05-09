package simpleethernet;

simple TrafficGen {
    parameters:
    	@display("i=block/app2");
    	int payloadLength @unit(B);
    	volatile double period @unit(s);
    	string destination;
    	double startTime @unit(s) = default(-1s);
    	int burstSize = default(1);
    	string flow;
    	
    	@signal[E2eDelay];
    	@signal[BurstE2eDelay];
    	@signal[Throughput];
    	@statistic[E2eDelay](record=vector);
    	@statistic[BurstE2eDelay](record=vector);
    	@statistic[Throughput](record=vector, last);
    
    gates:
        output lowerLayerOut;
        input lowerLayerIn;
}
