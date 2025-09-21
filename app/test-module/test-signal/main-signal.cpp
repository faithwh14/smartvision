#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <thread>

std::atomic<bool> g_running{true};

void SignalHandler(int sig) {
  std::cout << "Caught signal " << sig << ", shutting down...\n";
  g_running = false;
}

int main() {
  // Register handler for Ctrl+C (SIGINT) and kill (SIGTERM)
  std::signal(SIGINT, SignalHandler);
  std::signal(SIGTERM, SignalHandler);

  while (g_running) {
    std::cout << "Working...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  std::cout << "Clean exit.\n";
  return 0;
}
