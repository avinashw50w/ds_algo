/*
Design a meeting scheduler
requirements:
- we need to schedule a meeting from start time to end time which will have 
  'capacity' number or members attending the meeting
- we have a set of rooms, each having some capacity in which we can schedule the meeting
- we need to track the meetings via a calender

*/

class Meeting {
  constructor(public startTime: Date, public endTime: Date, public members: string[], public title: string) {}
}

class MeetingRoom {
  private meetings: Meeting[] = [];

  constructor(public id: number, public capacity: number) {}

  scheduleMeeting(meeting: Meeting): boolean {
    if (this.isAvailable(meeting.startTime, meeting.endTime) && meeting.members.length <= this.capacity) {
      this.meetings.push(meeting);
      return true;
    }
    return false;
  }

  isAvailable(startTime: Date, endTime: Date): boolean {
    for (const meeting of this.meetings) {
      if (meeting.startTime <= startTime && startTime < meeting.endTime) {
        return false; // Overlapping meeting
      }
      if (meeting.startTime < endTime && endTime <= meeting.endTime) {
        return false; // Overlapping meeting
      }
    }
    return true;
  }

  listMeetings(): Meeting[] {
    return this.meetings;
  }
}

class MeetingManager {
  private meetingRooms: MeetingRoom[] = [];

  addMeetingRoom(room: MeetingRoom) {
    this.meetingRooms.push(room);
  }

  scheduleMeeting(meeting: Meeting): boolean {
    for (const room of this.meetingRooms) {
      if (room.scheduleMeeting(meeting)) {
        this.sendInvites(meeting.members, meeting.title);
        return true;
      }
    }
    return false; // No available room for the meeting
  }

  sendInvites(members: string[], title: string) {
    for (const member of members) {
      console.log(`Inviting ${member} to the meeting: ${title}`);
    }
  }

  listMeetings(): Meeting[] {
    const allMeetings: Meeting[] = [];
    for (const room of this.meetingRooms) {
      allMeetings.push(...room.listMeetings());
    }
    return allMeetings;
  }

  getAvailableRooms(startTime: Date, endTime: Date, capacity: number): MeetingRoom[] {
    return this.meetingRooms.filter(meetingRoom => meetingRoom.capacity >= capacity && meetingRoom.isAvailable(startTime, endTime));
  }
}

// Usage
const manager = new MeetingManager();
const roomA = new MeetingRoom(1, 10);
const roomB = new MeetingRoom(2, 8);

manager.addMeetingRoom(roomA);
manager.addMeetingRoom(roomB);

const startTime = new Date(2023, 10, 21, 9, 0);
const endTime = new Date(2023, 10, 21, 10, 0);

const members = ['User1', 'User2', 'User3'];
const title = 'Project Meeting';

const meeting = new Meeting(startTime, endTime, members, title);

const isScheduled = manager.scheduleMeeting(meeting);

if (isScheduled) {
  console.log(`Meeting "${title}" scheduled successfully.`);
} else {
  console.log('Meeting could not be scheduled.');
}
