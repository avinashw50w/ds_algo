template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
    ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }

    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }

    ModInt operator/=(ModInt rhs) {
        static const ll inv2 = ModInt(2).inv().x;
        ll i = (rhs.x == 2 ? inv2 : rhs.inv().x);
        x = x * i % MOD; return *this;
    }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    ModInt inv() { return pow(MOD - 2); }
    ModInt pow(ll n) const {
        ModInt r = 1, t = x;
        for (; n; n >>= 1, t *= t) if (n & 1) r *= t;
        return r;
    }
};
typedef ModInt<1000000007> Mint;
