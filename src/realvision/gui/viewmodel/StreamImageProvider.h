#pragma once

#include <QObject>
#include <QQuickImageProvider>

namespace rv {

class StreamImageProvider : public QQuickImageProvider {
 public:
  StreamImageProvider(ImageType type);
  ~StreamImageProvider();
};

}  // namespace rv
