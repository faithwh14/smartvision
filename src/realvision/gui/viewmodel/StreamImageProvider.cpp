#include "StreamImageProvider.h"

namespace rv {

StreamImageProvider::StreamImageProvider(ImageType type) : QQuickImageProvider(type) {}

StreamImageProvider::~StreamImageProvider() {}

}  // namespace rv
