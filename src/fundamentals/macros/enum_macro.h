typedef enum {
  napi_ok,
  napi_invalid_arg,
  napi_object_expected,
  napi_string_expected,
  napi_name_expected,
  napi_function_expected,
  napi_number_expected,
  napi_boolean_expected,
  napi_array_expected,
  napi_generic_failure,
  napi_pending_exception,
  napi_cancelled,
  napi_escape_called_twice,
  napi_handle_scope_mismatch,
  napi_callback_scope_mismatch,
  napi_queue_full,
  napi_closing,
  napi_bigint_expected,
  napi_date_expected,
} napi_status;

#define FOREACH_STATUS(STATUS)                   \
        STATUS(napi_ok)                          \
        STATUS(napi_invalid_arg)                 \
        STATUS(napi_object_expected)             \
        STATUS(napi_string_expected)             \
        STATUS(napi_name_expected)               \
        STATUS(napi_function_expected)           \
        STATUS(napi_number_expected)             \
        STATUS(napi_boolean_expected)            \
        STATUS(napi_array_expected)              \
        STATUS(napi_generic_failure)             \
        STATUS(napi_pending_exception)           \
        STATUS(napi_cancelled)                   \
        STATUS(napi_escape_called_twice)         \
        STATUS(napi_handle_scope_mismatch)       \
        STATUS(napi_callback_scope_mismatch)     \
        STATUS(napi_queue_full)                  \
        STATUS(napi_closing)                     \
        STATUS(napi_bigint_expected)             \
        STATUS(napi_date_expected)


#define GENERATE_STRING(STRING) #STRING,

static const char* status_strings[] = {
    FOREACH_STATUS(GENERATE_STRING)
};

static const char* something(napi_status status) {
  return status_strings[status];
}
