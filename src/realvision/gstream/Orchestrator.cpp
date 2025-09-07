#include "Orchestrator.h"

namespace rv {

Orchestrator::Orchestrator() {}

Orchestrator::~Orchestrator() {}

void Orchestrator::AddRtspClient(std::string id, std::unique_ptr<RtspClient> client) {
  m_rtspClients.emplace(id, std::move(client));
}

}  // namespace rv
