#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

enum class QuestionStatus{
  OPEN,
  CLOSED,
  ON_HOLD,
  DELETED
};

enum class QuestionClosingRemark{
  DUPLICATE,
  OFF_TOPIC,
  TOO_BROAD,
  NOT_CONSTRUCTIVE,
  NOT_A_REAL_QUESTION,
  PRIMARILY_OPINION_BASED
};

enum class AccountStatus{
  ACTIVE,
  CLOSED,
  CANCELED,
  BLACKLISTED,
  BLOCKED
};

class Address {
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};



// Badge, Tag, and Notification: Members have badges, questions have tags and notifications
class Badge {
    string name;
    string description;
};

class Tag {
    string name;
    string description;
    long int dailyAskedFrequency;
    long int weeklyAskedFrequency;
};

class Notification {
    int notificationId;
    time_t createdOn;
    string content;

    bool sendNotification();
};


class Question;
class Comment;
class Answer;

// Account, Member, Admin, and Moderator: These classes represent the different people that interact with our system:
// For simplicity, we are not defining getter and setter functions. The reader can
// assume that all class attributes are private and accessed through their respective
// getter methods and modified only through their methods function.

class Account {
    string id;
    string password;
    AccountStatus status;
    string name;
    Address address;
    string email;
    string phone;
    int reputation;

    bool resetPassword();
};

class Member {
    Account account;
    vector<Badge> badges;

    int getReputation();
    string getEmail();
    bool createQuestion(Question question);
    bool createTag(Tag tag);
};

class Admin : public Member {
    bool blockMember(Member member);
    bool unblockMember(Member member);
};

class Moderator : public Member {
    bool closeQuestion(Question question);
    bool undeleteQuestion(Question question);
};




//Photo and Bounty: Members can put bounties on questions. Answers and Questions can have multiple photos:
class Photo {
    int photoId;
    string photoPath;
    time_t creationDate;

    Member creatingMember;

    bool deletePhoto();
};

class Bounty {
    int reputation;
    time_t expiry;

  bool modifyReputation(int reputation);
};


// Question, Comment and Answer: Members can ask questions, as well as add an answer to any question. All members can add comments to all open questions or answers:
class Search {
    virtual vector<Question> search(string query) = 0;
};

class Question: public Search {
    string title;
    string description;
    int viewCount;
    int voteCount;
    time_t creationTime;
    time_t updateTime;
    QuestionStatus status;
    QuestionClosingRemark closingRemark;

    Member askingMember;
    Bounty bounty;
    vector<Photo> photos;
    vector<Comment> comments;
    vector<Answer> answers;

public:
    bool close();
    bool undelete();
    bool addComment(Comment comment);
    bool addBounty(Bounty bounty);

    vector<Question> search(string query) {
    // return all questions containing the string query in their title or description.
    };
};

class Comment {
    string text;
    time_t creationTime;
    int flagCount;
    int voteCount;

    Member askingMember;

public:
    bool incrementVoteCount();
};

class Answer {
    string answerText;
    bool accepted;
    int voteCount;
    int flagCount;
    time_t creationTime;

    Member creatingMember;
    vector<Photo> photos;

public:
    bool incrementVoteCount();
};

int main() {
    return 0;
}
