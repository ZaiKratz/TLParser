#include "../Public/SentCodeTypeApp.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeApp::SentCodeTypeApp()
{
	this->_ConstructorID = 1035688326;
}

SentCodeTypeApp::SentCodeTypeApp(int32 length)
{
	this->_ConstructorID = 1035688326;
	this->length = length;
}
void SentCodeTypeApp::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->length);
}


void SentCodeTypeApp::OnResponce(BinaryReader& Reader)
{
	length = Reader.ReadInt();
	this->_Responded = true;
}
SentCodeTypeApp::~SentCodeTypeApp()
{
}
}//end namespace block
