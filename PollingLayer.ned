package simpleethernet;

simple PollingLayer {
    parameters:
    	@display("i=block/timer");
    	int burstSize;
    	string flow;
    	string controllerAddress;
    gates:
        input lowerLayerIn;
        output lowerLayerOut;
        input upperLayerIn;
        output upperLayerOut;
}
