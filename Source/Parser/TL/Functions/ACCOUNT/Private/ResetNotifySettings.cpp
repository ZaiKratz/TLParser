#include "../Public/ResetNotifySettings.h"


//begin namespace block
namespace ACCOUNT
{

ResetNotifySettings::ResetNotifySettings()
{
	this->_ConstructorID = -612493497;
	this->_ContentRelated = true;
}
void ResetNotifySettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ResetNotifySettings::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ResetNotifySettings::~ResetNotifySettings()
{

}
}//end namespace block
