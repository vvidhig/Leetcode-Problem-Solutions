struct Meeting
{
    int start;
    int end;
    int position;
    Meeting(int start, int end, int position) : start(start), end(end), position(position) {};
};

bool static meetingsComparator(Meeting &m1, Meeting m2)
{
    if(m1.end < m2.end)
    {
        return true;
    }
    else if(m2.end < m1.end)
    {
        return false;
    }
    else if(m1.position < m2.position)
    {
        return true;
    }
    else
    {
        return false;
    }
}


class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<Meeting> meetings;
        int n = start.size();
        for(int i = 0; i<n; i++)
        {
            meetings.push_back(Meeting(start[i], end[i], i));
        }
        sort(meetings.begin(), meetings.end(), meetingsComparator);
        vector<int> meetingsOrder;
        int prevmeeting = meetings[0].end;
        meetingsOrder.push_back(meetings[0].position);
        for(int i = 1; i<n; i++)
        {
            if(meetings[i].start>prevmeeting)
            {
                meetingsOrder.push_back(meetings[i].position);
                prevmeeting = meetings[i].end;
            }
        }
        return meetingsOrder.size();
    }
};
