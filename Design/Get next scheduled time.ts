/* Given jobs and the time when it should run. The jobs can also be scheduled for either 
daily, weekly, montly or yearly. We can also set the schedule interval.
eg. frequency = montly,
interval = 3 // every 3 months

*/

interface ISchedule {
  getNextScheduledTime(timestamp: Date): Date;
}

class DailySchedule implements ISchedule {
  constructor(private interval: number) {}

  getNextScheduledTime(timestamp: Date): Date {
    const nextTime = new Date(timestamp);
    nextTime.setDate(nextTime.getDate() + this.interval);
    return nextTime;
  }
}

class WeeklySchedule implements ISchedule {
  constructor(private interval: number) {}

  getNextScheduledTime(timestamp: Date): Date {
    const nextTime = new Date(timestamp);
    nextTime.setDate(nextTime.getDate() + 7 * this.interval);
    return nextTime;
  }
}

class MonthlySchedule implements ISchedule {
  constructor(private interval: number) {}

  getNextScheduledTime(timestamp: Date): Date {
    const nextTime = new Date(timestamp);
    nextTime.setMonth(nextTime.getMonth() + this.interval);
    return nextTime;
  }
}

class YearlySchedule implements ISchedule {
  constructor(private interval: number) {}

  getNextScheduledTime(timestamp: Date): Date {
    const nextTime = new Date(timestamp);
    nextTime.setFullYear(nextTime.getFullYear() + this.interval);
    return nextTime;
  }
}

// Example usage
const now = new Date();

const dailySchedule = new DailySchedule(3); // Every 3 days
const nextDailyTime = dailySchedule.getNextScheduledTime(now);

const weeklySchedule = new WeeklySchedule(2); // Every 2 weeks
const nextWeeklyTime = weeklySchedule.getNextScheduledTime(now);

const monthlySchedule = new MonthlySchedule(4); // Every 4 months
const nextMonthlyTime = monthlySchedule.getNextScheduledTime(now);

const yearlySchedule = new YearlySchedule(1); // Every year
const nextYearlyTime = yearlySchedule.getNextScheduledTime(now);

console.log('Next Daily Time:', nextDailyTime);
console.log('Next Weekly Time:', nextWeeklyTime);
console.log('Next Monthly Time:', nextMonthlyTime);
console.log('Next Yearly Time:', nextYearlyTime);
