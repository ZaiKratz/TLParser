#include "../Public/UpdateStatus.h"


//begin namespace block
namespace ACCOUNT
{

UpdateStatus::UpdateStatus()
{
	this->_ConstructorID = 743843942;
	this->_ContentRelated = true;
}

UpdateStatus::UpdateStatus(bool offline)
{
	this->_ConstructorID = 743843942;
	this->_ContentRelated = true;
	this->offline = offline;
}
void UpdateStatus::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteBool(this->offline);
}


void UpdateStatus::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
UpdateStatus::~UpdateStatus()
{

}
}//end namespace block
