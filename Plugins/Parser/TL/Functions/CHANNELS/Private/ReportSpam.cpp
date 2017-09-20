#include "../Public/ReportSpam.h"


//begin namespace block
namespace CHANNELS
{

ReportSpam::ReportSpam()
{
	this->_ConstructorID = 276302078;
	this->_ContentRelated = true;
}

ReportSpam::ReportSpam(COMMON::InputChannel* channel, COMMON::InputUser* user_id, TArray<int32> id)
{
	this->_ConstructorID = 276302078;
	this->_ContentRelated = true;
	this->channel = channel;
	this->user_id = user_id;
	this->id = id;
}
void ReportSpam::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void ReportSpam::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ReportSpam::~ReportSpam()
{

}
}//end namespace block
