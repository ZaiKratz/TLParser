#include "../Public/PrivacyKeyStatusTimestamp.h"


//begin namespace block
namespace COMMON
{

PrivacyKeyStatusTimestamp::PrivacyKeyStatusTimestamp()
{
	this->_ConstructorID = -1137792208;
}
void PrivacyKeyStatusTimestamp::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyKeyStatusTimestamp::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PrivacyKeyStatusTimestamp::~PrivacyKeyStatusTimestamp()
{
}
}//end namespace block
