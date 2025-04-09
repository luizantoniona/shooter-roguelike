#include "Runner.h"

BEGIN_RUNNER_NAMESPACE

Runner::Runner() {
}

void Runner::setRunnerCallback( RunnerCallback callback ) {
    _runnerCallback = std::move( callback );
}

END_RUNNER_NAMESPACE