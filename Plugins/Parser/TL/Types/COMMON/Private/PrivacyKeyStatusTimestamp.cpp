#include "../Public/PrivacyKeyStatusTimestamp.h"


//begin namespace block
namespace COMMON
{

PrivacyKeyStatusTimestamp::PrivacyKeyStatusTimestamp()
{
	this->_ConstructorID = 816524988;
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
}
PrivacyKeyStatusTimestamp::~PrivacyKeyStatusTimestamp()
{

}
}//end namespace block
