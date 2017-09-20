#pragma once
#include "Engine.h"
#include "../../../Types/Private/ReportReason.h"

#include "../../../Types/Private/ReportReason.h"

//begin namespace block
namespace COMMON
{
class InputReportReasonSpam : public PRIVATE::ReportReason
{
public:
	InputReportReasonSpam();
	~InputReportReasonSpam();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
