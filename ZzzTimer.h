/***************************************************************
  ZzzTimer.h
***************************************************************/
#ifndef ZZZ_TIMER_H
#define ZZZ_TIMER_H

/** Callback to receive timer notifications */
typedef void(*ZzzTimerCallback)();


/**
 * Class to manage a timer.
 */
class ZzzTimer {
	protected:
		/** Interval between two callback calls */
		unsigned long _intervalMs;
		unsigned long _lastRequestMs=0;

		ZzzTimerCallback _callback=nullptr;

	public:
		/** Set the callback to call. */
		void setCallback(ZzzTimerCallback callback) {
			_callback=callback;
		}
	
		/** To call frequently (ie: in Arduino loop) */
		void update() {
			//check elapsed time (overflow proof)
			if (millis() - _lastRequestMs > _intervalMs) {
				_lastRequestMs=millis();

				if (_callback!=nullptr) {
					_callback();
				}
			}
		}

		/**
		 * Constructor 
		 * @param intervalMs minimum time in milliseconds to wait before next driver requests.
		 */
		ZzzTimer(unsigned long intervalMs) {
			_intervalMs=intervalMs;
		}
};

#endif

