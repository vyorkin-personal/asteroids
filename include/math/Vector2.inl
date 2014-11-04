const Vector2<T> Vector2<T>::zero = Vector2(static_cast<T>(0), static_cast<T>(0));
const Vector2<T> Vector2<T>::one = Vector2(static_cast<T>(1), static_cast<T>(1));

template <class T>
Vector2<T>::Vector2(const T x, const T y): x{x}, y{y} {}

template <class T>
T Vector2<T>::distance(const Vector2<T>& other) const {
    return sqrt(distanceSquared(other));
}

template <class T>
T Vector2<T>::distanceSquared(const Vector2<T>& other) const {
    Vector2<T> diff(*this);
    diff -= other;
    return diff.lengthSquared();
}

template <class T>
T Vector2<T>::dot(const Vector2<T>& other) const {
    return x * other.x + y * other.y;
}

template <class T>
T Vector2<T>::cross(const Vector2<T>& other) const {
    return x * other.y - y * other.x;
}

template <class T>
void Vector2<T>::normalize() {
    const T l = length();
    if (l != 0) {
	const T f = 1.0 / l;
	x = x * f;
	y = y * f;
    }
}

template <class T>
T Vector2<T>::direction() const {
    return atan2(x, y);
}

template <class T>
T Vector2<T>::length() const {
    return sqrt(lengthSquared());
}

template <class T>
T Vector2<T>::lengthSquared() const {
    return x * x + y * y;
}

template <class T>
Vector2<T>& Vector2<T>::rotate(const T angle) {
    const T s = sin(angle);
    const T c = cos(angle);

    const T nx = x * c - y * s;
    const T ny = x * s + y * c;

    x = nx;
    y = ny;

    return *this;
}

template <class T>
bool Vector2<T>::operator == (const Vector2<T>& other) const {
    return x == other.x && y == other.y;
}

template <class T>
bool operator != (const Vector2<T>& other) const {
    return x != other.x || y != other.y;
}

template <class T>
Vector2<T> operator - () const {
    return Vector2(-x, -y);
}

template <class T>
Vector2<T> operator + (const Vector2<T>& other) const {
    return Vector2(x + other.x, y + other.y);
}

template <class T>
Vector2<T> operator - (const Vector2<T>& other) const {
    return Vector2(x - other.x, y - other.y);
}

template <class T>
Vector2<T> operator * (const Vector2<T>& other) const {
    return Vector2(x * other.x, y * other.y);
}

template <class T>
Vector2<T> operator / (const Vector2<T>& other) const {
    return Vector2(x / other.x, y / other.y);
}

template <class T>
Vector2<T> operator + (const T value) const {
    return Vector2(x + value, y + value);
}

template <class T>
Vector2<T> operator - (const T value) const {
    return Vector2(x - value, y - value);
}

template <class T>
Vector2<T> operator * (const T value) const {
    return Vector2(x * value, y * value);
}

template <class T>
Vector2<T> operator / (const T value) const {
    return Vector2(x / value, y / value);
}

template <class T>
Vector2<T>& operator += (const Vector2<T>& other) {
    x += other.x;
    y += other.y;
    return *this;
}

template <class T>
Vector2<T>& operator -= (const Vector2<T>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template <class T>
Vector2<T>& operator *= (const Vector2<T>& other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

template <class T>
Vector2<T>& operator /= (const Vector2<T>& other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

template <class T>
Vector2<T>& operator += (const T value) {
    x += value;
    y += value;
    return *this;
}

template <class T>
Vector2<T>& operator -= (const T value) {
    x -= value;
    y -= value;
    return *this;
}

template <class T>
Vector2<T>& operator *= (const T value) {
    x *= value;
    y *= value;
    return *this;
}

template <class T>
Vector2<T>& operator /= (const T value) {
    x /= value;
    y /= value;
    return *this;
}

