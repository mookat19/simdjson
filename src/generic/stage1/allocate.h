namespace stage1 {
namespace allocate {

//
// Allocates stage 1 internal state and outputs in the parser
//
really_inline error_code set_capacity(internal::dom_parser_implementation &parser, size_t capacity) {
  size_t max_structures = ROUNDUP_N(capacity, 64) + 2 + 7;
  parser.structural_indexes.reset( new (std::nothrow) uint32_t[max_structures] );
  if (!parser.structural_indexes) { return MEMALLOC; }
  return SUCCESS;
}

} // namespace allocate
} // namespace stage1
