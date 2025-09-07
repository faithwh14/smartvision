#include <iostream>

namespace rv {

class OnnxRuntime {
 public:
  OnnxRuntime();
  ~OnnxRuntime();

  void RunPreprocess();
  void RunBatchInference();
  void RunPostprocess();

  void SetNMSThreshold(int threshold);
  void SetConfThreshold(int threshold);

 private:
  void processNMS();
  void encodeFrame();
  void decodeFrame();
};

}  // namespace rv
