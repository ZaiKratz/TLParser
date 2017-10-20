#include "../Public/PrivacyValueDisallowAll.h"


//begin namespace block
namespace COMMON
{

PrivacyValueDisallowAll::PrivacyValueDisallowAll()
{
	this->_ConstructorID = -1955338397;
}
void PrivacyValueDisallowAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyValueDisallowAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PrivacyValueDisallowAll::~PrivacyValueDisallowAll()
{
}
}//end namespace block
