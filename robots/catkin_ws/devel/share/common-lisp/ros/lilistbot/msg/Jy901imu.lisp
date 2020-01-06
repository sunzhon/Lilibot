; Auto-generated. Do not edit!


(cl:in-package lilistbot-msg)


;//! \htmlinclude Jy901imu.msg.html

(cl:defclass <Jy901imu> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass Jy901imu (<Jy901imu>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Jy901imu>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Jy901imu)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lilistbot-msg:<Jy901imu> is deprecated: use lilistbot-msg:Jy901imu instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <Jy901imu>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lilistbot-msg:data-val is deprecated.  Use lilistbot-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Jy901imu>) ostream)
  "Serializes a message object of type '<Jy901imu>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Jy901imu>) istream)
  "Deserializes a message object of type '<Jy901imu>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Jy901imu>)))
  "Returns string type for a message object of type '<Jy901imu>"
  "lilistbot/Jy901imu")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Jy901imu)))
  "Returns string type for a message object of type 'Jy901imu"
  "lilistbot/Jy901imu")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Jy901imu>)))
  "Returns md5sum for a message object of type '<Jy901imu>"
  "f43a8e1b362b75baa741461b46adc7e0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Jy901imu)))
  "Returns md5sum for a message object of type 'Jy901imu"
  "f43a8e1b362b75baa741461b46adc7e0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Jy901imu>)))
  "Returns full string definition for message of type '<Jy901imu>"
  (cl:format cl:nil "uint8[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Jy901imu)))
  "Returns full string definition for message of type 'Jy901imu"
  (cl:format cl:nil "uint8[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Jy901imu>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Jy901imu>))
  "Converts a ROS message object to a list"
  (cl:list 'Jy901imu
    (cl:cons ':data (data msg))
))
