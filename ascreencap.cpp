
#include "ascreencap.h"
#include "ascreencap-AScreenConf.h"
#include "ascreencap-ABitmapLite.h"
#include "ascreencap-AScreenCap.h"
#include "extern/argh.h"
#include <binder/ProcessState.h>

int main(int argc, char **argv)
{
#   if defined(_DEBUG)
    auto _t1 = HClockNow();
#   endif

    android::ProcessState::self()->startThreadPool();
    ACapture::AScreenConf cnf(argc, argv);
    ACapture::AScreenCap sc;

    sc.setRatio(cnf.Ratio);
    sc.setRotate(cnf.Rotate);

#   if defined(_DEBUG)
    auto _t2 = HClockNow();
#   endif

    if (cnf.IsCapFile)
    {
        if (sc.getScreen())
        {
#           if defined(_DEBUG)
            auto _t3 = HClockNow();
#           endif

            if (!sc.getError())
                if (sc.saveFile(cnf.FileName, cnf.IsPackFile, cnf.FastPack))
                {
#                   if defined(_DEBUG)
                    auto _t4 = HClockNow();
                    auto _d2 = HClockDiff(_t2, _t1);
                    auto _d3 = HClockDiff(_t3, _t2);
                    auto _d4 = HClockDiff(_t4, _t3);
                    auto _d0 = HClockDiff(_t4, _t1);
                    __LOG_PRINT(
                        "End, load (ms.) -> base: [%lld], capture: [%lld], image: [%lld], total: [%lld] | internal-err: [%d]",
                        _d2, _d3, _d4, _d0, sc.getError()
                        );
#                   endif
                    return 0;
                }
        }


        __LOG_PRINT("Capture Error [%d]", sc.getError());
        return 127;
    }
    else if (cnf.IsCapStream)
    {
        sc.getStream(cnf.FastPack);
    }
    return 0;
}
