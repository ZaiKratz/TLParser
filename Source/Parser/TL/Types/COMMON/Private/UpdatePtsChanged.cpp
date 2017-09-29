#include "../Public/UpdatePtsChanged.h"


//begin namespace block
namespace COMMON
{

UpdatePtsChanged::UpdatePtsChanged()
{
	this->_ConstructorID = 861169551;
}
void UpdatePtsChanged::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdatePtsChanged::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdatePtsChanged::~UpdatePtsChanged()
{

}
}//end namespace block
