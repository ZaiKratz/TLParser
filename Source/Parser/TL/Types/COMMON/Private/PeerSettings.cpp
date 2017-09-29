#include "../Public/PeerSettings.h"


//begin namespace block
namespace COMMON
{

PeerSettings::PeerSettings()
{
	this->_ConstructorID = -2122045747;
}

PeerSettings::PeerSettings(bool report_spam)
{
	this->_ConstructorID = -2122045747;
	this->report_spam = report_spam;
}
void PeerSettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(report_spam)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void PeerSettings::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		report_spam = true;
	}
	this->_Responded = true;
}
PeerSettings::~PeerSettings()
{

}
}//end namespace block
