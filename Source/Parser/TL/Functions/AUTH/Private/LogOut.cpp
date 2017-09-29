#include "../Public/LogOut.h"


//begin namespace block
namespace AUTH
{

LogOut::LogOut()
{
	this->_ConstructorID = 1461180992;
	this->_ContentRelated = true;
}
void LogOut::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void LogOut::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
LogOut::~LogOut()
{

}
}//end namespace block
