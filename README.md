
# Domus

### Backend
- **C++**
- **Bazel**
- **Bazelisk**
- **gRPC**
- **Protocol Buffers**

---
### Requirements

To build and run this project, you need:

- Git
- Bazelisk
- C++ toolchain
- Xcode on macOS, or equivalent compiler toolchain on Linux

---
### Supported Environment

Currently tested primarily on:

- macOS
- Apple Silicon / arm64
- Bazel 8.5.0

---
### Installation

1. Clone the repository:
```powershell
git clone https://github.com/dorin-curnic/domus.git
cd domus
```

2. Install Bazelisk
```powershell
brew install bazelisk
```

---
### macOS Setup

If you are using macOS, make sure full Xcode is installed.

1. Set active developer directory
```powershell
sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
```

2. Run first launch setup
```powershell
sudo xcodebuild -runFirstLaunch
```

3. Accept the Xcode license
```powershell
sudo xcodebuild -license
```

---
### Build

Build the server and client
```powershell
bazelisk build //domus:domus_server //domus:domus_client
```

---
### Run

Start the server
```powershell
bazelisk run //domus:domus_server
```

Start the client
```powershell
bazelisk run //domus:domus_client
```

The server starts locally on
```powershell
127.0.0.1:8080
```

Current demo output
```
FOOBAR hello
```

---
## Repository Structure

```text
.
├── domus
│   ├── BUILD
│   ├── domus_client.cpp
│   ├── domus_server.cpp
│   └── domus.proto
├── frontend
├── .bazelrc
├── .bazelversion
├── MODULE.bazel
├── MODULE.bazel.lock
└── README.md
```

---
### Troubleshooting 

Make sure .bazelversion contains only:
```text
8.5.0
```

Build cache / dependency issue
```powershell
rm -f MODULE.bazel.lock
bazelisk clean --expunge
bazelisk build //domus:domus_server //domus:domus_client
```

