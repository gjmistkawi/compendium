# std::lock_guard

## Explanation

The lock_guard locks a mutex upon construction, and releases when it goes out of scope, including when an exception is thrown. There are no additional use-cases.

## Compared to std::unique_lock

Lock_guard is extremely simple and only has a constructor and destructor. While unique_lock is able to unlock and relock the mutex it is assigned, a lock_guard only unlocks at its destruction. Similar to unique_lock, lock_guard will unlock at an exception throw. Lock_guard, however, cannot be move-assigned because it is always engaged with a reference to a mutex, so it is unable to let go of it's current mutex and hand the mutex off.

## Functions

- (constructor)
- (destructor)