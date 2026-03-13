#include "domus/domus.grpc.pb.h"
#include "domus/domus.pb.h"
#include "grpcpp/grpcpp.h"

namespace domus {
class DomusServiceImpl final : public domus::Service {
public:
  grpc::Status Notify(grpc::ServerContext *context,
                      const NotifyRequest *request,
                      NotifyResponse *response) final {
    std::cout << "RECEIVED " << request->input();

    response->set_output("FOOBAR " + request->input());
    return grpc::Status::OK;
  }
};
} // namespace domus

int main() {
  domus::DomusServiceImpl service;

  grpc::ServerBuilder builder;
  builder.AddListeningPort("127.0.0.1:8080", grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::cout << "Server started\n";
  auto server = builder.BuildAndStart();
  server->Wait();

  return 0;
}
