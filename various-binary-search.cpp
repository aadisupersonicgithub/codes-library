
auto ok = [&] (i64 tmp) {
  return (rand() & 1) % 2 == 0; 
};
i64 le = 0, ri = 2e18, ans = ri;
for (int it = 0; it < 80; ++it) {
    i64 md = (le + ri) / 2;
    if (ok(md)) {
      ans = md;
      le = md + 1;  
    } else {
      ri = md - 1;
    }
}

i64 le = 1, ri = 2e9, md1, md2, ans = 0; 
auto ok = [&] (i64 x) {
  return ((x - 1) + (n + x - 1) / x); 
};
for (i64 it = 0; it < 60; ++it) {    
    i64 md = (le + ri) / 2;
    if (ok(md) < ok(le)) {
      le = md + 1;
      ans = ok(md); 
    } else {
      ri = md - 1; 
    }
    md1 = le + (ri - le) / 3, md2 = ri - (ri - le) / 3;
    if (ok(md1) < ok(md2)) {
      ans = ok(md2);
      le = md1;  
    }
    else {
      ans = ok(md1); 
      ri = md2; 
    }
} 
for (i64 i = le; i <= ri; ++i) {
    if (ok(i) < ok(ans)) {
        ans = i; 
    }
}
// todo : find first element from left or right satisfying some prop.
// compare md with le or ri for prefix_property type binary ones.
// 2 pointer ka 1 template 
auto okaySir = [&] (int i) {

};
auto add = [&] (int i) {

};
auto remove = [&] (int i) {

};
int r = -1;
for (int i = 0; i < n; ++i) {
  while (r + 1 < n and okay_sir(r + 1)) {
    add(r + 1);
    ++r;
  }
  // [i, r]
  remove(i);
}

auto okay = [&] (int id) {

};
auto add = [&] (int id) {

};
auto remove = [&] (int id) {

};
int r = 0;
for (int i = 0; i < n; ++i) {
  while (r < n and !okay(r)) {
    add(r);
    ++r;
  }
  // [i, r)
  remove(i);
}
