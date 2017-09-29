#pragma once
#include "Engine.h"
#include "../../../Types/Private/ReportReason.h"

#include "../../../Types/Private/ReportReason.h"

//begin namespace block
namespace COMMON
{
class InputReportReasonPornography : public PRIVATE::ReportReason
{
public:
	InputReportReasonPornography();
	~InputReportReasonPornography();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
