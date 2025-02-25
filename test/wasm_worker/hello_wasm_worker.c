#include <assert.h>
#include <emscripten/wasm_worker.h>
#include <stdio.h>

// This is the code example in site/source/docs/api_reference/wasm_workers.rst

void run_in_worker()
{
  printf("Hello from wasm worker!\n");
#ifdef REPORT_RESULT
  REPORT_RESULT(0);
#endif
}

int main()
{
  emscripten_wasm_worker_t worker = emscripten_malloc_wasm_worker(/*stack size: */1024);
  assert(worker);
  emscripten_wasm_worker_post_function_v(worker, run_in_worker);
}
