;; Auto-generated. Do not edit!


(when (boundp 'lilistbot::Jy901imu)
  (if (not (find-package "LILISTBOT"))
    (make-package "LILISTBOT"))
  (shadow 'Jy901imu (find-package "LILISTBOT")))
(unless (find-package "LILISTBOT::JY901IMU")
  (make-package "LILISTBOT::JY901IMU"))

(in-package "ROS")
;;//! \htmlinclude Jy901imu.msg.html


(defclass lilistbot::Jy901imu
  :super ros::object
  :slots (_data ))

(defmethod lilistbot::Jy901imu
  (:init
   (&key
    ((:data __data) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _data __data)
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; uint8[] _data
    (* 1    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8[] _data
     (write-long (length _data) s)
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8[] _data
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _data (make-array n :element-type :char))
     (replace _data buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get lilistbot::Jy901imu :md5sum-) "f43a8e1b362b75baa741461b46adc7e0")
(setf (get lilistbot::Jy901imu :datatype-) "lilistbot/Jy901imu")
(setf (get lilistbot::Jy901imu :definition-)
      "uint8[] data

")



(provide :lilistbot/Jy901imu "f43a8e1b362b75baa741461b46adc7e0")


