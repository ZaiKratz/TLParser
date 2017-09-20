#include "../Public/ReceivedQueue.h"


//begin namespace block
namespace MESSAGES
{

ReceivedQueue::ReceivedQueue()
{
	this->_ConstructorID = 1723573589;
	this->_ContentRelated = true;
}

ReceivedQueue::ReceivedQueue(int32 max_qts)
{
	this->_ConstructorID = 1723573589;
	this->_ContentRelated = true;
	this->max_qts = max_qts;
}
void ReceivedQueue::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->max_qts);
}


void ReceivedQueue::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();
	int32 Count = Reader.ReadLong();
	for(int32 i = 0; i < Count; i++)
	{
		this->result.Add(Reader.ReadLong());
	}
}
ReceivedQueue::~ReceivedQueue()
{

}
}//end namespace block
