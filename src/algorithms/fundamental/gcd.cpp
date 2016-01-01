/*
 * Greatest Common divisor/factor (the largest integer that divides both
 * a and b).
 *
 * The size of a and b is cut in least in half giving O(Log N).
 */
int gcd(unsigned int a, unsigned int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

/*
 * Notes
 * -----
 * Remember that when dividing we have:
 * A
 * - = Q remainder R
 * B
 *
 * A = the dividend
 * B = the divisor
 * Q = the quotent
 * R = the remainder
 *
 * gcd(A, 0) = A
 * gcd(B, 0) = B
 * All ints evenly divide into zero since we can write c * 0 = 0. So A must evenly divide 0.
 *
 * gcd(A, B) = gcd(B, A-B)
 *
 */
