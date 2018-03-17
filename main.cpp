#include "Blockchain.h"
#include "Block.h"
#include <stdlib.h>
//#include "mykernel.cl.h"
//
//#ifdef __APPLE__
//#include <OpenCL/opencl.h>
//#else
//#include <CL/cl.h>
//#endif


int main() {
    Blockchain bChain = Blockchain();
    Block bl1 = Block(1,"number1");
    for(int i = 0; i<10;i++){
        bl1.addTransaction(Transaction(1,20,30));
    }

    bl1.calculateMerkle();
//    int err;
//    cl_device_id device_id;
//    cl_uint maxComputeUnits;
//
//    err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
//    if (err != CL_SUCCESS)
//        return EXIT_FAILURE;
//
//    err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(maxComputeUnits), &maxComputeUnits, NULL);
//    if (err != CL_SUCCESS)
//        return EXIT_FAILURE;

//    cout<<"parallel Compute Units is "<< maxComputeUnits;

//     cout << "Mining block 1..." << endl;
//     bChain.AddBlock(Block(1, "Block 1 Data"));
//
  //   cout << "Mining block 2..." << endl;
    // bChain.AddBlock(Block(2, "Block 2 Data"));

    // cout << "Mining block 3..." << endl;
     //bChain.AddBlock(Block(3, "Block 3 Data"));

    return 0;
}
