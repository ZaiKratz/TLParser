#include "../Public/PrivacyValueAllowAll.h"


//begin namespace block
namespace COMMON
{

PrivacyValueAllowAll::PrivacyValueAllowAll()
{
	this->_ConstructorID = -2105851291;
}
void PrivacyValueAllowAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyValueAllowAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PrivacyValueAllowAll::~PrivacyValueAllowAll()
{

}
}//end namespace block
