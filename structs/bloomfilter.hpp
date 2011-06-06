template<class T>
struct BloomFilter {
  long _filter;
  long (*_encode)(T* o);

  long defaultEncode(T* o) {
    return 0|*o;
  }

  BloomFilter() {
    filter_ = 0;
    _encode = &defaultEncode;
  }

  BloomFilter(long (*encode)(T* object)) {
    filter_ = 0;
    _encode = encode;
  }

  bool test (T *o) {
    return _encode(o) & _filter;
  }

  void add(T *o) {
    _filter &= _encode(o);
  }
};
