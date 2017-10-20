#include "../Public/ChannelParticipantsSearch.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsSearch::ChannelParticipantsSearch()
{
	this->_ConstructorID = 106343499;
}

ChannelParticipantsSearch::ChannelParticipantsSearch(FString q)
{
	this->_ConstructorID = 106343499;
	this->q = q;
}
void ChannelParticipantsSearch::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
}


void ChannelParticipantsSearch::OnResponce(BinaryReader& Reader)
{
	q = Reader.TGReadString();
	this->_Responded = true;
}
ChannelParticipantsSearch::~ChannelParticipantsSearch()
{
}
}//end namespace block
