from datetime import datetime

# Activity log stores all the logs from an activity/exercise
# This should be created at launch but we could consider automating that
class ActivityLog:
    # Initialisation, nothing to note
    def __init__(self, name:str=None) -> bool:
        if name is None:
            return false
        self.name = name
        self.size = 0
        self.logs = []
        return true


    # Add a new instance of the log class to append to the bottom
    # of the activity file
    def addLog(self, toAdd:'Log'=None) -> bool:
        if toAdd is None:
            return false

        self.logs.append(toAdd)
        return true

    def getSize(self) -> int:
        return size

    # Print one log by specifying an index
    def readOne(self, index:int=None) -> bool:
        if index is None:
            return false
        if index >= size:
            return false
        
        print(this.logs[index])
        return true

    # Print all logs
    def readAll(self) -> bool:
        for log in logs:
            print(f"Time: {log.getFormattedTime()}"+
            f"\tWhat: {log.getDesc()}"+
            f"\tSuccess: {log.getSuccess}"+
            f"\tRed Team: {log.getRT}")
        
        return true

    # Print all logs from auto tasks
    def readAllAuto(self) -> bool:
        for log in logs:
            if log.getRT == false:
                print(f"Time: {log.getFormattedTime()}"+
                f"\tWhat: {log.getDesc()}"+
                f"\tSuccess: {log.getSuccess}"+
                f"\tRed Team: {log.getRT}")
        
        return true

    # Print all logs from RT tasks
    def readAllRT(self) -> bool:
        for log in logs:
            if log.getRT:
                print(f"Time: {log.getFormattedTime()}"+
                f"\tWhat: {log.getDesc()}"+
                f"\tSuccess: {log.getSuccess}"+
                f"\tRed Team: {log.getRT}")
        
        return true

# A log stores information about a certain activity the server
# has attempted
class Log:
    # description   - A string description of what happened
    # success       - A bool determining success
    # time          - datetime of when it was attempted
    # redTeam       - A bool determining if the action was a redTeam request or not
    def __init__(self, description:str=None, success:bool=None, redTeam:bool=None):
        if description is None or success is None or redTeam is None:
            return false
        self.created = datetime.now()
        self.name = "Log from " & str(self.created)
        self.success = success
        self.redTeam = redTeam

        return true

    # Return the time
    def getFormattedTime(self) -> str:
        formattedOutput = created.hour + ":" + created.minute + ":" + created.second
        return formattedOutput

    # Return the description
    def getDesc(self) -> str:
        return description

    # Return the result
    def getSuccess(self) -> bool:
        return success

    # Return red team
    def getRT(self) -> bool:
        return redTeam