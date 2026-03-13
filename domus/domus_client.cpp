#include "domus/domus.grpc.pb.h"
#include "domus/domus.pb.h"
#include "grpcpp/grpcpp.h"

int main() {
  auto channel =
      grpc::CreateChannel("127.0.0.1:8080", grpc::InsecureChannelCredentials());
  auto stub = domus::domus::NewStub(channel);

  grpc::ClientContext context;
  domus::NotifyRequest request;
  domus::NotifyResponse response;

  request.set_input("hello");
  auto status = stub->Notify(&context, request, &response);
  if (!status.ok()) {
    std::cerr << status.error_message();
    return 1;
  }

  std::cout << response.output();
  return 0;
}
