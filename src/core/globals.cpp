#include "core/Globals.hpp"

namespace shi::core {

    static RuntimeData g_runtime;

    RuntimeData& data() {
        return g_runtime;
    }

    void reset() {
        g_runtime = RuntimeData();
    }

}
