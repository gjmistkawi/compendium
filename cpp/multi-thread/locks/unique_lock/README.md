# std::unique_lock

## Explanation

The unique_lock locks a mutex upon declaration, and releases when it goes out of scope, or when an exception is thrown. Can be unlocked and locked again. Is unique, and therefore cannot be copied, but can be move-assigned. 

## Compared to std::lock_guard

Uniqe_lock is slightly slower and takes up slightly more space than lock_guard. Unlike lock_guard, unique_lock can unlock a mutex and lock it again, giving it more versatility. Both types of locks unlock when they fall out of scope, although unique_lock also unlocks if an exception is thrown.

## Functions

- lock
- unlock
- try_lock
- try_lock_for
- try_lock_until
- owns_lock
- swap
- release
- (constructor)
- (destructor)