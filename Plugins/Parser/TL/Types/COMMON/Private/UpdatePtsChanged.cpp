#include "../Public/UpdatePtsChanged.h"


//begin namespace block
namespace COMMON
{

UpdatePtsChanged::UpdatePtsChanged()
{
	this->_ConstructorID = -1889053645;
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
}
UpdatePtsChanged::~UpdatePtsChanged()
{

}
}//end namespace block
